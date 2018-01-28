package chapter3

type ElementType = int
type PtrToNode = *Node
type List = PtrToNode
type Position = PtrToNode

type Node struct {
	element ElementType
	next    *Node
}

func MakeEmpty(l List) List {
	if l != nil {

	}
}

func IsEmpty(l List) {
	return l.next == nil
}

func IsLast(p Position, l List) {
	return p.next == nil
}

func Find(x ElementType, l List) Position {
	p := l.next
	for p != nil && p.element != x {
		p = p.next
	}
	return p
}

func FindPrevious(x ElementType, l List) Position {
	p := l
	for p.next != nil && p.next.element != x {
		p = p.next
	}
	return p
}
