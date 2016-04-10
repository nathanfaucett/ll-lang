import "core-memory" as mem;
import Mutex from "core-mutex";


pub struct Ref<T> {
    mutex: Mutex;
    count: usize;
    value: T;
}

impl Ref<T> {
    fn new(value: T) *Ref<T> {
        let ref: *Ref<T> = mem::alloc(sizeof(Ref<T>));
        ref->value = value;
        ref->count = 1;
        return ref;
    }

    fn ref(self, value: T): bool {
        self->mutex.lock();
        self->count++;
        self->mutex.unlock();
        return self;
    }
    fn deref(self, value: T): bool {
        self->mutex.lock();
        if (--self->count == 0) {
            return true;
        }
        self->mutex.unlock();
        return false;
    }
}
