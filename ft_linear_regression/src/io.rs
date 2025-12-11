use std::{error::Error, fs, fs::File};
use csv::Reader;

use crate::Model;

pub fn read_csv_raw(path: &str) -> Result<(Vec<f64>, Vec<f64>), Box<dyn Error>> {
    let mut rdr = Reader::from_reader(File::open(path)?);
    let mut x_km = Vec::new();
    let mut y = Vec::new();
    
    for rec in rdr.records() {
        let r = rec?;
        let mileage_km: f64 = r[0].parse()?;
        let price:      f64 = r[1].parse()?;
        x_km.push(mileage_km);
        y.push(price);
    }
    Ok((x_km, y))
}

pub fn save_model(m: &Model, path: &str) -> Result<(), Box<dyn Error>> {
    fs::write(path, serde_json::to_string_pretty(m)?)?;
    Ok(())
}
