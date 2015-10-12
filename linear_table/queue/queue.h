#ifndef ARRAY_H
#define ARRAY_H value
#define DEFAULT_SIZE 100
#ifndef NULL
#define NULL 0
#endif
struct _Node{
	int value;
	struct _Node *next;
};

class Iterator;
class Queue
{
public:
	friend class Iterator;
	Queue();
	~Queue();
	void append(int value);
	Iterator createIterator();
	int get();
private:
	struct _Node *_head;
	struct _Node *_current;
	struct _Node *_prev;
	void _initNode();
	void _appendNode(int val);
	int _popFirstNode();
};

class Iterator
{
public:
	Iterator(Queue * q);
	~Iterator();
	int next();
private:
	Queue *_queue;
	struct _Node *_cur;
};
#endif