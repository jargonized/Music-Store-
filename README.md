# Music-Store
'Music Store Management', implemented using C++, aims to efficiently provide major services to both the client and server end. This software is bundled with features so as to not only improve the quality of services provided but also to secure the store's data and avoid data redundancy.

This project is broadly divided into two categories- Customer and Employee. The customer end lets one place an order, view the details of the items* available so on and so forth.
The Employee end comes with two modules. The first module is the secured login page and the second module becomes accessible if and only if the first module grants access. The second module comes with options which enables one to work with the store's data as well manipulate the employee's details**.

*The store houses music albums and various musical instruments.

**Employee's details only include the Employee ID and their user password. 

Note: This project was completed 5 years ago for my high school final project. Documenting here for my reference.

FILES USED:
1.	BILL.DAT                 - Used to record all the generated bills.  
                                              -  Structure used:
                                                         struct Bill
                                                        {int id;
                                                         char Category[20],Name[100];
                                                         long Qty;
                                                         float total;
                                                            };
2.	ALBUM.DAT            - Used to store the information of the albums available
	                                    - Structure used: 
                              struct Album
                                                         {char Name[100],Category[20],
                                                           char Type[10],Artist[100];
                                                           float price; int id;
                                                           long Qty;
                                                            };
3.	INSTRU.DAT      -Used to store the information of the instruments available
                                        -Structure used:
                                                        struct Instrument
                                                         {char Name[50],Category[20];
                                                           float price;
                                                           long Qty;  int id;
                                                           };
4.	EMP.DAT            -Used to store the login details of the employees
                                        - Structure used:
                              struct Employee
                                                        {int i;
                                                         char pas[9];
                                                         };

