use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

const PRIORITY: &str = "abcdefghijklmnopqrstuvwxyz";

fn main() {
    run_on_input("3".to_string(), &day);
}

fn day(_l: String) -> i32 { return 0 }

fn run_on_input(day: String, _f: &dyn Fn(String) -> i32) {
    let mut total = 0;
    let mut line_n = 1;
    let mut line1: String = String::new();
    let mut line2: String = String::new();
    let mut line3: String = String::new();
    let mut ignore: String = String::new();

    if let Ok(lines) = read_lines(format!("./inputs/day{}.txt", day)) {
        // Consumes the iterator, returns an (Optional) String
        for line in lines {
            if let Ok(l) = line {
                match line_n {
                    1 => line1 = l.clone(),
                    2 => line2 = l.clone(),
                    3 => line3 = l.clone(),
                    _ => {}
                }

                line_n += 1;
                if line_n == 4 {
                    for c in line1.chars() {
                        if line2.find(c) != None && line3.find(c) != None {
                            if let Some(prio) = PRIORITY.find(c) {
                                if ignore.find(c) == None {
                                    ignore.push(c);
                                    total += prio + 1;
                                    let n = prio + 1;
                                    print!("{c} - {n}\n")
                                }
                            } else {
                                if let Some(prio) = PRIORITY.find(c.to_ascii_lowercase()) {
                                    if ignore.find(c) == None {
                                        ignore.push(c);
                                        total += prio + 27;
                                        let n = prio + 27;
                                        print!("{c} - {n}\n")
                                    }
                                }
                            }
                        }
                    }

                    line_n = 1;
                    ignore = String::new();
                }
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
