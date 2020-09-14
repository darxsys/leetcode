impl Solution {
    pub fn count_letters(s: String) -> i32 {
        let mut res: i32 = 0;
        let chars: Vec<char> = s.chars().collect();
        
        for i in 0..chars.len() {
            res = res + 1;
            for j in (i+1)..chars.len() {
                if (chars[j] != chars[i]) {
                    break;
                }
                res = res + 1;
            }
        }
        
        return res;
            
    }
}
