use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::convert::TryInto;

const PRIORITY: &str = "abcdefghijklmnopqrstuvwxyz";

fn main() {
    run_on_input("3".to_string(), &day);
}

fn day(l: String) -> i32{
    let length = l.chars().count();
    let half = length / 2;

    let first = &l[0..half];
    let second = &l[half..length];
    let mut ignore: String = String::new();
    let mut total = 0;

    for c in first.chars() {
        if second.find(c) != None {
            if let Some(prio) = PRIORITY.find(c) {
                if ignore.find(c) == None {
                    ignore.push(c);
                    total += prio + 1;
                    let n = prio + 1;
                }
            } else {
                if let Some(prio) = PRIORITY.find(c.to_ascii_lowercase()) {
                    if ignore.find(c) == None {
                        ignore.push(c);
                        total += prio + 27;
                        let n = prio + 27;
                    }
                }
            }
        }
    }

    return total.try_into().unwrap();
}

fn run_on_input(day: String, f: &dyn Fn(String) -> i32) {
    let mut total = 0;

    if let Ok(lines) = read_lines(format!("./inputs/day{}.txt", day)) {
        // Consumes the iterator, returns an (Optional) String
        for line in lines {
            if let Ok(l) = line {
                total += f(l);
            }
        }
    }

    print!("{total}");
}

// The output is wrapped in a Result to allow matching on errors
// Returns an Iterator to the Reader of the lines of the file.
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
