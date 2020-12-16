class Allocator {
private:
	struct Memory {
	    Memory *next;
	    Memory *prev;
	    void *userData;
	    Memory *nextFree;
	    Memory *prevFree;
	};

public:
	Allocator(arguments);
	virtual ~Allocator();

	void Merge(Memory *mem1, Memory *mem2) {
		if (mem2 != this->tail) {
			if (!mem1->IsFree() || !mem2->IsFree()) {
				return;
			}

			if (mem1->GetPtr() >= mem2->GetPtr()) {
				return;
			}

			if (mem1->next != mem2) {
				return;
			}

			mem1->next = mem2->next;
			mem1->nextFree = mem2->nextFree;

			if (mem1->next != NULL) {
				mem1->next->prev = mem1;
			}

			if (mem1->nextFree != NULL) {
				mem1->nextFree->prevFree = mem1;
			}
		}
	}
};
