import "core-memory" as mem;
import IList from "core-IList";
import ListNode from "./list_node";


pub struct List<T> {
    root: *ListNode<T>;
    tail: *ListNode<T>;
    size: usize;
}

impl List<T> {
    pub fn new(): *List<T> {
        let list = (*List<T>) mem::alloc(sizeof(List<T>));
        list->root = null;
        list->tail = null;
        list->size = 0;
        return list;
    }
}

impl IList<T> for List<T> {
    pub fn size(self): usize {
        return self->size;
    }
}
