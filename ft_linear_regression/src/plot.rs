use plotters::prelude::*;
use plotters::prelude::IntoLogRange;

use crate::SCALE_X;

pub fn plot_loss(history: &[f64], out_svg: &str) -> Result<(), Box<dyn std::error::Error>> {
    if history.is_empty() { return Ok(()); }

    let rmse_raw: Vec<f64> = history.iter().map(|&m| m.sqrt()).collect();

    let eps = 1e-9;
    let rmse: Vec<f64> = rmse_raw.iter().map(|&v| v.max(eps)).collect();

    let mut ymin = rmse.iter().copied().fold(f64::INFINITY, f64::min);
    let mut ymax = rmse.iter().copied().fold(f64::NEG_INFINITY, f64::max);
    if (ymax - ymin).abs() < f64::EPSILON {
        ymin = (ymin / 2.0).max(eps);
        ymax = ymax * 2.0;
    }

    let root = SVGBackend::new(out_svg, (1000, 700)).into_drawing_area();
    root.fill(&WHITE)?;
    let mut chart = ChartBuilder::on(&root)
        .margin(42)
        .caption("Evolution of Prediction Error (RMSE)", ("sans-serif", 22))
        .x_label_area_size(40)
        .y_label_area_size(58)
        .build_cartesian_2d(0..(rmse.len() - 1), (ymin..ymax).log_scale())?;

    chart.configure_mesh()
        .x_desc("Training Iteration")
        .y_desc("Average Prediction Error (RMSE, in €)")
        .y_labels(12)
        .y_label_formatter(&|v| format!("{:.0}", v))
        .axis_style(&BLACK.mix(0.6))
        .light_line_style(&BLACK.mix(0.06)) 
        .label_style(("sans-serif", 13))
        .draw()?;

    chart.draw_series(LineSeries::new(
        rmse.iter().enumerate().map(|(i, &v)| (i, v)),
        &BLUE,
    ))?;

    Ok(())
}

pub fn plot_fit(
    x_km: &[f64],
    y: &[f64],
    theta0: f64,
    theta1: f64,
    out_svg: &str,
) -> Result<(), Box<dyn std::error::Error>> {
    if x_km.is_empty() || x_km.len() != y.len() {
        return Ok(());
    }

    let xmin = x_km.iter().copied().fold(f64::INFINITY, f64::min);
    let xmax = x_km.iter().copied().fold(f64::NEG_INFINITY, f64::max);
    let ymin = y.iter().copied().fold(f64::INFINITY, f64::min);
    let ymax = y.iter().copied().fold(f64::NEG_INFINITY, f64::max);

    let xr = (xmax - xmin).abs();
    let yr = (ymax - ymin).abs();
    let xr = if xr == 0.0 { 1.0 } else { xr };
    let yr = if yr == 0.0 { 1.0 } else { yr };

    let xlo = xmin - xr * 0.05;
    let xhi = xmax + xr * 0.05;
    let ylo = ymin - yr * 0.05;
    let yhi = ymax + yr * 0.05;

    let root = SVGBackend::new(out_svg, (1000, 700)).into_drawing_area();
    root.fill(&WHITE)?;
    let mut chart = ChartBuilder::on(&root)
        .margin(42)
        .caption("Price vs Mileage (fit)", ("sans-serif", 22))
        .x_label_area_size(36)
        .y_label_area_size(76)
        .build_cartesian_2d(xlo..xhi, ylo..yhi)?;

    chart.configure_mesh()
        .x_desc("Mileage (km)")
        .y_desc("Price")
        .axis_style(&BLACK.mix(0.6))
        .light_line_style(&BLACK.mix(0.06))
        .label_style(("sans-serif", 13))
        .draw()?;

    let y1 = theta0 + theta1 * (xlo / SCALE_X);
    let y2 = theta0 + theta1 * (xhi / SCALE_X);
    chart.draw_series(std::iter::once(PathElement::new(
        vec![(xlo, y1), (xhi, y2)],
        ShapeStyle {
            color: RED.mix(0.9),
            filled: false,
            stroke_width: 2,
        },
    )))?
    .label("Linear fit")
    .legend(|(x, y)| PathElement::new(vec![(x, y), (x + 20, y)], RED.stroke_width(2)));

    chart.draw_series(
        x_km.iter().zip(y).map(|(xr, yr)| Circle::new((*xr, *yr), 3, BLUE.filled()))
    )?
    .label("Data")
    .legend(|(x, y)| Circle::new((x, y), 3, BLUE.filled()));

    chart.configure_series_labels()
        .border_style(&BLACK.mix(0.4))
        .background_style(&WHITE.mix(0.8))
        .label_font(("sans-serif", 12))
        .draw()?;

    Ok(())
}
