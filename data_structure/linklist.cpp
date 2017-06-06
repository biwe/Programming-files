/*
 * Linklist.cpp
 * this is just a excise program.
 * this includes create, insert, search ,delete..
 *
 * Created on: June 5, 2017
 * Author: bv_user
 */

#include <iostream>
using namespace std;

struct stu{
	int num;
	stu* next;
};

void create(stu* head){
	char input;
	cout<< "add number: y/n ";
	cin>>input;
	while(input == 'y'){
		stu* newlink = new stu;
		cout << "input number:";
		cin >> newlink->num;
		newlink->next = head->next;
		head->next = newlink;
		cout<< "add number: y/n ";
		cin>>input;
	}
}

void del_all(stu* head){
	// after head to detect
	for(stu* inter=head->next; inter->next!=NULL;){
		stu* del = inter;
		cout<<inter->num<<endl;
		inter = inter->next;
		delete del;
		cout<<"delete success"<<endl;
	}
}

void ins_af(stu* start, int num, int num_af){
	while(start->next!=NULL){
		if(start->num==num_af){
			stu* inter = new stu;
			inter->num = num;
			inter->next = start->next;
			start->next = inter;
			cout<< "insert success" << num<<endl;
			return;
		}
		start = start->next; //caution condition
	}
	cout<<"have no data num_af";
}

void del_num(stu* head, int num){
	stu* cur_pre = head;
	stu* cur = head->next;
	while(cur->next!=NULL){
		if(cur->num==num){
			cur_pre->next = cur->next;
			delete cur;
		}
		cur_pre = cur;
		cur = cur->next;
	}
}

int main(){
	stu end={0, NULL};
	/*end.next = NULL;
	end.num = 0;*/
	stu head = {0, &end};
//	head.num = 0;
//	head.next = &end;
	char input;
	create(&head);

	cout<< "insert number: y/n" <<endl;
	cin>>input;
	while(input=='y'){
		cout << "input number"<<endl;
		int in_num;
		int af_num;
		cin>>in_num;
		cout << "input number after:"<<endl;
		cin>>af_num;
		ins_af(head.next, in_num, af_num);
		cout<< "insert number: y/n" <<endl;
		cin>>input;
	}

	cout<< "delete number: y/n" <<endl;
	cin>>input;
	while(input=='y'){
		int d_num;
		cout<< "input number:";
		cin >> d_num;
		del_num(&head, d_num);
		cout<< "delete success"<<endl;
		cout<< "delete number: y/n" <<endl;
		cin>>input;
	}

	del_all(&head);

	return 0;
}
