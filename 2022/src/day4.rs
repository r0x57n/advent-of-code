use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
    run_on_input("4".to_string(), &day_second);
}

fn day_first(l: String) -> i32 {
    let split = l.split(",").collect::<Vec<_>>();
    let first: Vec<i32> = split[0]
        .split("-")
        .map(|s| s.parse().expect("parse error"))
        .collect();
    let second: Vec<i32> = split[1]
        .split("-")
        .map(|s| s.parse().expect("parse error"))
        .collect();

    if first[0] <= second[0] && second[1] <= first[1] {
        // print!("{l}\n");
        // print!("{} <= {} && {} <= {}\n\n", first[0], second[0], second[1], first[1]);
        return 1;
    }

    if second[0] <= first[0] && first[1] <= second[1] {
        // print!("{l}\n");
        // print!("{} <= {} && {} <= {}\n\n", second[0], first[0], first[1], second[1]);
        return 1;
    }

    return 0;
}

fn day_second(l: String) -> i32 {
    let split = l.split(",").collect::<Vec<_>>();
    let first: Vec<i32> = split[0]
        .split("-")
        .map(|s| s.parse().expect("parse error"))
        .collect();
    let second: Vec<i32> = split[1]
        .split("-")
        .map(|s| s.parse().expect("parse error"))
        .collect();

    /*
    5-7,7-9 overlaps in a single section, 7.
    2-8,3-7 overlaps all of the sections 3 through 7.
    6-6,4-6 overlaps in a single section, 6.
    2-6,4-8 overlaps in sections 4, 5, and 6.
    */

    if first[0] <= second[0] && second[1] <= first[1] {
        print!{"First inside of second\n"}
        print!("{l}\n\n");
        return 1;
    }

    else if second[0] <= first[0] && first[1] <= second[1] {
        print!{"Second inside of first\n"}
        print!("{l}\n\n");
        return 1;
    }

    else if second[0] <= first[0] && second[1] >= first[0]{
        print!{"First inside of second\n"}
        print!("{l}\n\n");
        return 1;
    }

    else if first[0] <= second[0] && first[1] >= second[0]{
        print!{"Second inside of first\n"}
        print!("{l}\n\n");
        return 1;
    }

    // else if first[0] <= second[0] && first[1] <= second[1] {
    //     print!{"Part of first inside of second\n"}
    //     print!("{l}\n");
    //     print!("{} <= {} && {} <= {}\n\n", first[0], second[0], second[1], first[1]);
    //     return 1;
    // }

    // else if second[0] <= first[0] && second[1] <= first[1] {
    //     print!{"Part of second inside of first\n"}
    //     print!("{l}\n");
    //     print!("{} <= {} && {} <= {}\n\n", first[0], second[0], second[1], first[1]);
    //     return 1;
    // }

    print!{"No match\n"}
    print!("{l}\n\n");

    return 0;
}

fn run_on_input(day: String, f: &dyn Fn(String) -> i32) {
    let mut pairs = 0;

    if let Ok(lines) = read_lines(format!("./inputs/day{}.txt", day)) {
        for line in lines {
            if let Ok(l) = line {
                pairs += f(l);
            }
        }
    }

    print!("{pairs}")
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
