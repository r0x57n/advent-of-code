use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

const O_STONE: &str = "A";
const O_PAPER: &str = "B";
const O_SCISSOR: &str = "C";
const I_STONE: &str = "X";
const I_PAPER: &str = "Y";
const I_SCISSOR: &str = "Z";

const N_LOSE: &str = "X";
const N_DRAW: &str = "Y";
const N_WIN: &str = "Z";

const LOSS: i32 = 0;
const DRAW: i32 = 3;
const WON: i32 = 6;

const STONE: i32 = 1;
const PAPER: i32 = 2;
const SCISSOR: i32 = 3;


fn main() {
    let mut total_score = 0;

    if let Ok(lines) = read_lines("./inputs/day2.txt") {
        // Consumes the iterator, returns an (Optional) String
        for line in lines {
            if let Ok(l) = line {
                total_score += parse_line_second(l);
            }
        }
    }

    print!("{total_score}");
}

fn parse_line_first(l: String) -> i32 {
    let split = l.split(" ").collect::<Vec<_>>();
    let mut score = 0;

    match split[1] {
        I_STONE => score += STONE,
        I_PAPER => score += PAPER,
        I_SCISSOR => score += SCISSOR,
        _ => {}
    }

    match split[0] {
        O_STONE =>
            match split[1] {
                I_STONE => score += DRAW,
                I_PAPER => score += WON,
                I_SCISSOR => score += LOSS,
                _ => {}
            },
        O_PAPER =>
            match split[1] {
                I_STONE => score += LOSS,
                I_PAPER => score += DRAW,
                I_SCISSOR => score += WON,
                _ => {}
            },
        O_SCISSOR =>
            match split[1] {
                I_STONE => score += WON,
                I_PAPER => score += LOSS,
                I_SCISSOR => score += DRAW,
                _ => {}
            },
        _ => {}
    }

    return score;
}

fn parse_line_second(l: String) -> i32 {
    let split = l.split(" ").collect::<Vec<_>>();
    let mut score = 0;

    match split[1] {
        N_LOSE => score += LOSS,
        N_DRAW => score += DRAW,
        N_WIN => score += WON,
        _ => {}
    }

    match split[0] {
        O_STONE =>
            match split[1] {
                N_LOSE => score += SCISSOR,
                N_DRAW => score += STONE,
                N_WIN => score += PAPER,
                _ => {}
            },
        O_PAPER =>
            match split[1] {
                N_LOSE => score += STONE,
                N_DRAW => score += PAPER,
                N_WIN => score += SCISSOR,
                _ => {}
            },
        O_SCISSOR =>
            match split[1] {
                N_LOSE => score += PAPER,
                N_DRAW => score += SCISSOR,
                N_WIN => score += STONE,
                _ => {}
            },
        _ => {}
    }

    return score;
}

// The output is wrapped in a Result to allow matching on errors
// Returns an Iterator to the Reader of the lines of the file.
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
