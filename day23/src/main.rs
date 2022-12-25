use rustc_hash::FxHashSet;

const DIRS: [(i16, i16); 7] = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, 0), (1, 0), (0, -1)];
const D8: [(i16, i16); 8] = [
    (0, 1),
    (0, -1),
    (-1, 0),
    (1, 0),
    (1, 1),
    (1, -1),
    (-1, 1),
    (-1, -1),
];
type Elf = (i16, i16);
fn dest(elves: &FxHashSet<Elf>, elf: Elf, t: usize) -> Elf {
    if D8
        .iter()
        .all(|&(di, dj)| !elves.contains(&(di + elf.0, dj + elf.1)))
    {
        return elf;
    }
    for &(di, dj) in DIRS[t % 4..t % 4 + 4].iter() {
        if D8
            .iter()
            .filter(|&(ddi, ddj)| di * ddi + dj * ddj == 1)
            .all(|&(ddi, ddj)| !elves.contains(&(ddi + elf.0, ddj + elf.1)))
        {
            return (di + elf.0, dj + elf.1);
        }
    }
    elf
}

fn main() {
    let s = std::fs::read_to_string("input.txt").unwrap();
    let elves: FxHashSet<_> = s
        .lines()
        .enumerate()
        .flat_map(|(i, l)| {
            l.chars()
                .enumerate()
                .filter(|&(_j, c)| c == '#')
                .map(move |(j, _c)| (i as i16, j as i16))
        })
        .collect();
    {
        let mut elves = elves.clone();
        for i in 0..10 {
            step(&mut elves, i);
        }
        let imn = elves.iter().map(|e| e.0).min().unwrap();
        let imx = elves.iter().map(|e| e.0).max().unwrap();
        let jmn = elves.iter().map(|e| e.1).min().unwrap();
        let jmx = elves.iter().map(|e| e.1).max().unwrap();
        println!("{}", (imx - imn + 1) * (jmx - jmn + 1) - elves.len() as i16);
    }

    {
        let mut elves = elves.clone();
        for i in 0.. {
            if !step(&mut elves, i) {
                println!("{}", i + 1);
                break;
            }
        }
    }
}

fn step(elves: &mut FxHashSet<(i16, i16)>, i: usize) -> bool {
    let mut moved = 0;
    let prev = elves.clone();
    elves.clear();
    for &e in &prev {
        let ee = dest(&prev, e, i);
        moved += (ee != e) as u16;
        if !elves.insert(ee) {
            elves.remove(&ee);
            elves.insert(e);
            elves.insert((ee.0 * 2 - e.0, ee.1 * 2 - e.1));
            moved -= 2;
        }
    }
    moved > 0
}
