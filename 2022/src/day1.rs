use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
    let mut current_elf = 1;
    let mut current_amount = 0;

    let mut elfs: Vec<(i32, i32)> = Vec::new();

    if let Ok(lines) = read_lines("./inputs/day1.txt") {
        // Consumes the iterator, returns an (Optional) String
        for line in lines {
            if let Ok(l) = line {
                if l != "" {
                    current_amount += l.parse::<i32>().unwrap();
                } else {
                    elfs.push((current_elf, current_amount));
                    current_elf += 1;
                    current_amount = 0;
                }
            }
        }
    }

    elfs.sort_by_key(|k| k.1);
    elfs.reverse();

    let mut total = 0;
    for i in 0..=2 {
        total += elfs[i].1;
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
