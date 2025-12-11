use std::{error::Error, fs};

use ft_linear_regression::{
    Model,
    io::read_csv_raw,
    metrics::{evaluate_model, print_model_eval},
};

fn main() -> Result<(), Box<dyn Error>> {
    let (x_km, y) = read_csv_raw("data.csv")?;
    let json = fs::read_to_string("theta.json")?;
    let m: Model = serde_json::from_str(&json)?;
    let (rmse, mae, r2, mape) = evaluate_model(&x_km, &y, m.theta0, m.theta1);
    
    print_model_eval(rmse, mae, r2, mape);
    
    Ok(())
}
