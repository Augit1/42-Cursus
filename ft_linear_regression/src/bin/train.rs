use std::error::Error;
use clap::{Parser, ValueEnum};

use ft_linear_regression::{ 
    io::{read_csv_raw, save_model},
    plot::{plot_fit, plot_loss},
    preview::{save_frames, live_preview},
    Model, ITERATIONS,
};

#[derive(Copy, Clone, Debug, ValueEnum)]
enum PreviewMode {
    Theta,
    Freq,
}

#[derive(Parser, Debug)]
#[command(author, version, about = "Linear regression trainer")]
struct Cli {
    #[arg(long)]
    live_preview: bool,

    #[arg(long)]
    loss_plot: bool,

    #[arg(long, value_enum, default_value = "theta")]
    preview_mode: PreviewMode,

    #[arg(long, default_value_t = 50)]
    preview_freq: usize,

    #[arg(long, default_value_t = 3.0)]
    preview_diff: f64,
}

fn train(
    x_km: &[f64],
    y: &[f64],
    lr: f64,
    iters: usize,
    cli: &Cli
) -> Result<(f64, f64, Vec<f64>), Box<dyn Error>> {

    // Scaling
    let x_scaled: Vec<f64> = x_km.iter().map(|&km| km / ft_linear_regression::SCALE_X).collect();
    let m = x_scaled.len();
    assert!(m == y.len() && m > 0);

    let inv_m = 1.0 / (m as f64);
    let (mut t0, mut t1) = (0.0, 0.0);
    let mut prev_t1 = 0.0;

    let mut history = Vec::with_capacity(iters);

    for i in 0..=iters {
        let loss = x_scaled.iter().zip(y)
            .map(|(xi, yi)| {
                let err = (t0 + t1 * xi) - yi;
                err * err
            })
            .sum::<f64>() * inv_m;

        history.push(loss);

        // Gradient
        let (sum0, sum1) = x_scaled.iter().zip(y).fold((0.0, 0.0), |acc, (xi, yi)| {
            let err = (t0 + t1 * xi) - yi;
            (acc.0 + err, acc.1 + err * xi)
        });

        t0 -= lr * (sum0 * inv_m);
        t1 -= lr * (sum1 * inv_m);

        save_frames(x_km, y, t0, t1, i)?;

        if cli.live_preview {
            match cli.preview_mode {
                PreviewMode::Theta => {
                    let variation = ((t1 - prev_t1).abs() / prev_t1.abs().max(1e-12)) * 100.0;
                    if variation > cli.preview_diff {
                        live_preview(x_km, y, t0, t1, i)?;
                        prev_t1 = t1;
                    }
                }
                PreviewMode::Freq => {
                    if i % cli.preview_freq == 0 {
                        live_preview(x_km, y, t0, t1, i)?;
                    }
                }
            }
        }
    }

    Ok((t0, t1, history))
}

fn main() -> Result<(), Box<dyn Error>> {
    let cli = Cli::parse();
    let (x_km, y) = read_csv_raw("data.csv")?;
    let (theta0, theta1, history) = train(&x_km, &y, 1e-2, ITERATIONS, &cli)?;

    println!("θ0 = {theta0}, θ1 = {theta1}");
    save_model(&Model { theta0, theta1 }, "theta.json")?;
    plot_fit(&x_km, &y, theta0, theta1, "fit.svg")?;

    if cli.loss_plot {
        plot_loss(&history, "loss.svg")?;
        open::that("loss.svg")?;
    }
    Ok(())
}
