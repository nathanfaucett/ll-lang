

pub struct ListNode<T> {
    pub next: *ListNode<T>,
    pub value: T
}

impl ListNode<T> {

    pub fn new(next: *ListNode<T>, value: T): *List<T> {
        node := (*ListNode<T>) mem::alloc(sizeof(ListNode<T>));
        node->next = next;
        node->value = value;
        return node;
    }

    pub fn find(node: *ListNode<T>, value: T): *List<T> {

    }
}
