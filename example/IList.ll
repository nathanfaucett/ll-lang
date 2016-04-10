

pub interface IList<T> {
    pub fn size(self): *usize;

    pub fn get(self, index: usize): T;
    
    pub fn set(self, index: usize): *Self;
    pub fn remove(self, index: usize): *Self;

    pub fn push(self, value: T): *Self;
    pub fn unshift(self, value: T): *Self;

    pub fn pop(self): *Self;
    pub fn shift(self): *Self;
}
