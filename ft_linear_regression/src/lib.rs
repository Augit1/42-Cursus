use serde::{Serialize, Deserialize};

pub const SCALE_X: f64 = 100_000.0;
pub const ITERATIONS: usize = 5_000;

pub type DynResult<T = ()> = Result<T, Box<dyn std::error::Error>>;

#[derive(Serialize, Deserialize, Default)]
pub struct Model {
    pub theta0: f64,
    pub theta1: f64,
}

// modules
pub mod io;
pub mod plot;
pub mod metrics;
pub mod preview;
