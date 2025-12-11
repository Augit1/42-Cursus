use colored::Colorize;

use crate::SCALE_X;

pub fn evaluate_model(
    x_km: &[f64],
    y: &[f64],
    theta0: f64,
    theta1: f64,
) -> (f64, f64, f64, f64) {
    let n = y.len() as f64;
    let mut mse = 0.0;
    let mut mae = 0.0;
    let mut ss_tot = 0.0;
    let mut ss_res = 0.0;

    let y_mean = y.iter().sum::<f64>() / n;

    for (&x, &y_true) in x_km.iter().zip(y) {
        let y_pred = theta0 + theta1 * (x / SCALE_X);
        let e = y_pred - y_true;

        mse += e * e;
        mae += e.abs();
        ss_res += (y_true - y_pred).powi(2);
        ss_tot += (y_true - y_mean).powi(2);
    }

    mse /= n;
    mae /= n;

    let rmse = mse.sqrt();
    let r2 = 1.0 - ss_res / ss_tot;
    let mape = mae / y_mean * 100.0;

    (rmse, mae, r2, mape)
}

pub fn print_model_eval(rmse: f64, mae: f64, r2: f64, mape: f64) {
    let r2_label = if r2 >= 0.9 {
        "excellent"
    } else if r2 >= 0.75 {
        "good"
    } else if r2 >= 0.5 {
        "medium"
    } else {
        "weak"
    };

    let mape_label = if mape <= 5.0 {
        "excellent"
    } else if mape <= 10.0 {
        "good"
    } else if mape <= 20.0 {
        "acceptable"
    } else {
        "poor"
    };

    let title = "MODEL EVALUATION".bold().underline();
    println!("\n================ {} ================\n", title);

    println!("  RMSE :  {:8.2}€", rmse);
    println!("  MAE  :  {:8.2}€", mae);

    let r2_str = format!("{:.4} ({})", r2, r2_label);
    let r2_str = match r2_label {
        "excellent" | "good" => r2_str.green(),
        "medium"             => r2_str.yellow(),
        _                    => r2_str.red(),
    };
    println!("  R²   :    {}", r2_str);

    let mape_str = format!("{:.2}% ({})", mape, mape_label);
    let mape_str = match mape_label {
        "excellent" | "good" => mape_str.green(),
        "acceptable"         => mape_str.yellow(),
        _                    => mape_str.red(),
    };
    println!("  MAPE :    {}", mape_str);

    println!();
    println!(
        "{}",
        format!(
            "Summary: R² = {:.2} ({}), avg error ≈ {:.0} € (~{:.1}% of price).",
            r2, r2_label, mae, mape
        )
        .bold()
    );
    println!();
}
