resident)
            {
                if(head->isPresident)
                {
                    cout<<"President already Exist!!"<<endl;
                    cout<<"Do you want to add this as member?"<<endl;
                    char choice;
                    if(choice=='Y' || choice=='y')
                    {
                        add(name,PRN,false,false,head->next);
                        cout<<"added as member sucessfully!!"<<endl;
                        return;
                    }
                    else
                    {
                        return;
                    }
                }
            }