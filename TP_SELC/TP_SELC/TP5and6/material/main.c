#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct student {
 char lastname[30];
 char firstname[30];
 int group;
} Student_t;

typedef struct link{
     Student_t  student;
     struct link * next;
} Link_t;

Link_t * new_link(Student_t student);
Link_t * chain(Link_t * beginning, Link_t * new_link);
void display_linked_list(Link_t * list);
void free_list(Link_t * list);
Link_t * sort (Link_t * beginning);
Link_t * search (Link_t * beginning, char * name_to_search);
Link_t * insert (Link_t * beginning, Link_t * new_link);
void read_file_content(Student_t * array, FILE * file);

/*************   global variables   ****************/

Link_t * first_link = NULL;
int number_of_students = 0;

/********************   main   ********************/
int main(int argc, char*argv[]) {
  // First, we read the content of the file with the list of students
  // check that the user gave a correct number of parameters
  // Usage: ./sum_fscanf file_name
            if(argc!=2)
            {
              printf("Wrong usage: expected ./linked_list file_name");
              return -1;
            }

  // check for the occurence of errors when using fopen and fscanf,
  // display an error message and quit in case of errors.
            FILE * f = fopen(argv[1], "r");
            if (f == NULL)
            {
              printf("Error: could not open file %s, make sure it exists\n", argv[1]);
              return -2;
            }

            Student_t students_array [160];
            read_file_content(students_array, f);
            printf("dd");

  // visualize the content of students_array using printf
            int i;
            for(i = 0; i<number_of_students; i++)
              printf("%s %s %d",students_array[i].lastname, students_array[i].firstname, students_array[i].group);

  // create a linked list from the array of students
            for (i = 0; i < number_of_students; i++){
              first_link = chain(first_link, new_link( students_array[i]) );
            }

            printf ("\n-------------- Initial content of the list -------------- \n");
            display_linked_list(first_link);

  /********************   test search function  ********************/
            printf ("\n\n**************************************************\n");
            printf("Test of the \"search\" function ...\n");
            char name_to_search[80];
            do {
              printf("Enter a name to search (write END when finished testing): ");
              scanf("%s", name_to_search);
              Link_t * found_link = search(first_link, name_to_search);
              if (found_link != NULL)
              {
                printf("Found %s ! :  last name: %s first name: %s group: %d\n", name_to_search,
                  found_link->student.lastname, found_link->student.firstname,
                  found_link->student.group);
              }
              else
                printf("%s was not found  !\n", name_to_search);

            } while(strcmp(name_to_search, "END")!=0);
            printf("Test of the \"search\" function finished: evaluate the result.\n");
            printf ("**************************************************\n\n");

  /********************   test insertion  ********************/
            printf ("\n\n**************************************************\n");
            printf("Test of the \"insert\" function ...\n");
            Student_t student_z = { "ZZZ", "should_be_last",  42 };
            Student_t student_a = { "AAA", "should_be_first",  42 };
            Student_t student_o = { "OOO", "should_be_middle",  42 };

            Link_t * link_z = new_link(student_z);
            Link_t * link_a = new_link(student_a);
            Link_t * link_o = new_link(student_o);

            first_link = insert(first_link,link_z);
            first_link = insert(first_link,link_a);
            first_link = insert(first_link,link_o);

            printf ("-------------- Content of the list after insertion -------------- \n");
            display_linked_list(first_link);
            printf("Test of the \"insert\" function finished: evaluate the result.\n");
            printf ("**************************************************\n\n");

  /********************   test  sort    ********************/
            printf ("\n\n**************************************************\n");
            printf("Test of the \"sort\" function ...\n");
            Link_t * sorted_list = sort(first_link);
            printf ("-------------- Content of the list after sort -------------- \n");
            display_linked_list(sorted_list);
            printf("Test of the \"sort\" function finished: evaluate the result.\n");
            printf ("**************************************************\n\n");

  /*****  test free ********/
            printf ("\n\n**************************************************\n");
            printf("Test of the \"free_list\" function ...\n");
            free_list(first_link);
            printf("Test of the \"free_list\" function finished.\n");
            printf ("**************************************************\n\n");

            printf ("\n\n**************************************************\n");
            printf ("Tests passed?\n\t NO --> continue ! \n\t YES --> This is the end ... Hold your breath and count to ten ... Next: Makefiles and OS ... \n");
            printf ("**************************************************\n\n");
            return 0;
}

/********************   read_file_content   ********************
* read file and extract information to store it in array
**************************************************************/

void read_file_content(Student_t * array, FILE * file){

  /* TODO: implement this function */
  int i = 0;
  while(fscanf(file,"%s %s %d",array[i].lastname, array[i].firstname, &array[i].group) != EOF){
    i++;
    number_of_students++;
  }
  // printf("read_file_content: Not Implemented Yet\n");

}

/********************    new_link   *******************
* Create a new link of type Link_t: the field next is initialized to NULL
* Returns the adress of the new link.
********************************************************/
Link_t * new_link(Student_t student){
  Link_t *Ptr;

  /* TODO: implement this function */
  Ptr = malloc(sizeof(Link_t));
  Ptr->student = student;
  Ptr->next = NULL;

  return Ptr;
}

/********************    chain   *******************
* Add a new link (new_link) at the beginning of an existing
* linked list (beginning).
* Returns the address of the first element of the list.
********************************************************/
Link_t * chain(Link_t * beginning, Link_t * new_link){
  // Link_t *Ptr;

  /* TODO: implement this function */
  new_link->next = beginning;

  return new_link;
}

/********************   display_linked_list   *******************
* Display (using printf) the information contained in the
* linked list.
********************************************************/
void display_linked_list(Link_t * list){
  /* TODO: implement this function */
    while(list->next != NULL){
      printf("%30s %30s\t %d\n",(list)->student.lastname,(list)->student.firstname,(list)->student.group);
      list = list->next;
    }
}

/********************   search   *******************
* Search for a link corresponding to a student last
* name
* beginning: first link of the list used for searching
* name_to_search: last name of the student to search
* returns the firts link for which the name equals
* name_to_search
********************************************************/
Link_t * search (Link_t * beginning, char * name_to_search)
{
  Link_t * found_link;

  /* TODO: implement this function */
  int i = 0, found = 0;
  //tant qu'il n'atteint pas a la fin de la liste et qu'on n'a pas trouve
    while((found == 0) && (beginning->next != NULL)){
        found = 1;
      //si les deux caracteres sont differents, on change la valeur de 'found' en 0
        if(strcmp(name_to_search+i, beginning->student.lastname) != 0) found = 0;
      //si on a pas encore trouve, incrementer le pointer vers
      //le prochain element de la liste
        if(!found)beginning = beginning->next;
    }
  //si trouve, on enregistre par found_link le pointer vers l'element trouve
    if(found) found_link = beginning;
  return found_link;
}


/********************   insert   *******************
* Insert a link in a linked list
* beginning: first link of the original list
* new_link: link to insert
* returns the firts link of the list after insertion
********************************************************/
Link_t * insert (Link_t * beginning, Link_t * new_link)
{
  Link_t * list_after_insertion;
  list_after_insertion = ((strcmp(new_link->student.lastname, beginning->student.lastname)<0)?new_link:beginning);
  Link_t * last_Link = NULL;

    while(    (strcmp(new_link->student.lastname, beginning->student.lastname)>0)
          &&  (beginning->next != NULL))
    {
      last_Link = beginning;
      beginning = beginning->next;
    }

  if(last_Link != NULL)
    last_Link->next = new_link;

  new_link->next = beginning;

  return list_after_insertion;
}

/********************   sort   *******************
* Sort the content of the linked list.
********************************************************/
Link_t * sort (Link_t * beginning)
{
  Link_t * sorted_list = beginning;
  Link_t * last_Link=NULL;
  int sorted = 0;

  // if not sorted
    while(!sorted){
      sorted = 1;
      beginning = sorted_list;
      last_Link = NULL;

      // when it is not the end of the list, and we don"t find beginning > beginning.next
        while((beginning->next != NULL) && (sorted))
        {
          // if beginning > beginning.next, set 'not_sorted'
            if(strcmp(beginning->student.lastname, beginning->next->student.lastname) > 0) sorted = 0;
          // if not, remember the 'beginning' actual as the last one and
          // change 'beginning' to its next one
            else{
              last_Link = beginning;
              beginning = beginning->next;
            }
        }

      // if have beginning > beginning.next
        if(!sorted)
        {
          // if beginning is the first one, then pointer 'sorted_list' to the next of beginning actual
            if(beginning == sorted_list)  sorted_list = beginning->next;
          // if not, pointer 'last_Link' to the next of beginning actual
            else                          last_Link->next = beginning->next;
          // insert 'beginning' into the following list
            insert(beginning->next,beginning);
        }
    }

  return sorted_list;
}

/********************   free_list   *******************
* Free the memory used by the linked list.
********************************************************/
void free_list(Link_t * list){
  if(list->next != NULL)
    free_list(list->next);
  free(list);
}
