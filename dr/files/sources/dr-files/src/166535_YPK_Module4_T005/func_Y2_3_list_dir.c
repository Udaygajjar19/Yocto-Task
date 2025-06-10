
/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <dirent.h>

void call_list_dir(){
	char path[100];
	/* geting user input */
	printf("Enter path:");
	scanf("%s",path);
	list_dir(path);	
}

void list_dir(char *path){
	/*using inbuilt struct of dirent*/
	struct dirent *pDir;
	/*opening the given path*/
	DIR *dir = opendir(path);
	if (!dir) {
		/*if there is no file searched for*/
        	printf("Error: Unable to open directory\n");
        	return;
    	}
	
	/*it will read untill there is no file remaining to search*/
	while((pDir = readdir(dir)) != NULL){
		sort_linklist(pDir->d_name);
	}
	/*closing the directory*/
	closedir(dir);
	/* Displaying the list */
	display_linked_list();
}

typedef struct node{
	char *data;
	struct node * next;
}Node;


Node *head= NULL;
void sort_linklist(char *file_name){
	/* Allocating newNode dynamic memory */
	Node *newNode = (Node *)malloc(sizeof(Node));
	/* giving newnode filename */
	newNode->data = strdup(file_name);
	newNode->next = NULL;
	
	/*case if head is null or newnode strcmp is less than 0 than make it head*/
	if(!head || strcmp(newNode->data,head->data) < 0){
		newNode->next= head;
		head = newNode;
	}
	else{
		/*storing head in temporary variable*/
		Node *temp = head;
		/*if temp next is not null and strcmp is less than 0 till that link will travel*/
		while(temp->next && strcmp(temp->next->data,newNode->data)< 0 ){
			temp = temp->next;
		}
		/*appending the node at correct location*/
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void display_linked_list() {
    Node *temp = head;
    /*it will break it temp is null*/
    while (temp) {
        printf("%s\n", temp->data);
	/*going ahead in link*/
        temp = temp->next;
    }
}

