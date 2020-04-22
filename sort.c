#include "head.h"

void Sort(p_student left, p_student right) {

	if (left != right) {
		p_student partition_tag = Partition(left, right);
		Sort(left, partition_tag);
		Sort(partition_tag->p_next, right);
	}

}

p_student Partition(p_student left, p_student right) {

	int partition_tag = left->no;
	p_student p_cur = left->p_next;
	p_student p_pre = left;

	while (p_cur != right) {
		if (p_cur->no < partition_tag) {
			Swap(p_pre, p_cur);
			p_pre = p_pre->p_next;
		}
		p_cur = p_cur->p_next;
	}

	if (p_cur->no < p_pre->no) {
		Swap(p_pre->p_next, p_cur);
		Swap(p_pre->p_next, p_pre);
	}

	Swap(left, p_pre);
	return p_pre;

}

void Swap(p_student a, p_student b) {

	p_student tmp = (p_student)calloc(1, sizeof(student));

	tmp->no		= a->no;
	tmp->age	= a->age;
	tmp->sex	= a->sex;
	tmp->chnScr 	= a->chnScr;
	tmp->mahScr 	= a->mahScr;
	tmp->engScr 	= a->engScr;
	tmp->name[MAX_NAME_LEN - 1] = a->name[MAX_NAME_LEN - 1];

	a->no		= b->no;
	a->age		= b->age;
	a->sex		= b->sex;
	a->chnScr	= b->chnScr;
	a->mahScr	= b->mahScr;
	a->engScr	= b->engScr;
	a->name[MAX_NAME_LEN - 1] = b->name[MAX_NAME_LEN - 1];

	b->no		= tmp->no;
	b->age		= tmp->age;
	b->sex		= tmp->sex;
	b->chnScr	= tmp->chnScr;
	b->mahScr	= tmp->mahScr;
	b->engScr	= tmp->engScr;
	b->name[MAX_NAME_LEN - 1] = tmp->name[MAX_NAME_LEN - 1];

}
