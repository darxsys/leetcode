struct Solution ();

impl Solution {
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        use std::collections::HashSet;
        
        let mut result = HashSet::new();
        
        for pair in paths.iter() {
            if result.contains(&pair[0]) {
                result.remove(&pair[0]);
            }
            
            result.insert(&pair[1]);
        }
        
        for pair in paths.iter() {
            if result.contains(&pair[0]) {
                result.remove(&pair[0]);
            }
        }
        
        for ret in result {
            return String::from(ret);
        }
        
        return String::new();
    }
}

fn main() {
    let input: Vec<Vec<String>> = vec![vec!["London".to_string(),"New York".to_string()],
            vec!["New York".to_string(),"Lima".to_string()],vec!["Lima".to_string(),"Sao Paulo".to_string()]];
    println!("{}", Solution::dest_city(input));
}
