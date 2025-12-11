use std::fs;

use crate::{DynResult};
use crate::plot::plot_fit;

pub fn save_frames(x_km: &[f64], y: &[f64], t0: f64, t1: f64, iter: usize) -> DynResult {
    fs::create_dir_all("frames")?;
    if iter % 1000 == 0 {
        let filename = format!("frames/iter_{:05}.svg", iter);
        plot_fit(&x_km, &y, t0, t1, &filename)?;
    }
    Ok(())
}

pub fn live_preview(x_km: &[f64], y: &[f64], t0: f64, t1: f64, iter: usize) -> DynResult {
    let filename = "live_fit.svg";
    plot_fit(&x_km, &y, t0, t1, &filename)?;
    open::that(filename)?;
    println!("Iter number: {:?}\t θ0: {:?}\t θ1: {:?}", iter, t0, t1);
    Ok(())
}
