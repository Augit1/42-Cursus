use std::{error::Error, fs};
use std::io::{self, Write};

use ft_linear_regression::{Model, SCALE_X};

fn main() -> Result<(), Box<dyn Error>> {
    let m: Model = match fs::read_to_string("theta.json") {
        Ok(content) => serde_json::from_str(&content).unwrap_or_default(),
        Err(_) => Model::default(),
    };

    print!("Mileage ? ");
    io::stdout().flush()?;
    let mut s = String::new();
    io::stdin().read_line(&mut s)?;
    let mileage: f64 = s.trim().parse::<f64>().ok()
        .filter(|v| *v >= 0.0)
        .ok_or("Mileage must be a non-negative number")?;

    let x = mileage / SCALE_X;
    let price = (m.theta0 + m.theta1 * x).max(0.0).min(m.theta0);

    println!("{:.2}€", price);
    Ok(())
}
