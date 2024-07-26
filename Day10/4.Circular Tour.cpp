 int tour(petrolPump p[],int n)
    {
       int defecit=0,balance=0,f=0;
       
       
       for(int r=0;r<n;r++)
       {
           balance=balance+p[r].petrol-p[r].distance;
           
           if(balance<0)
           {
               defecit+=balance;
               f=r+1;
               balance=0;
           }
       }
       
       if(balance+defecit>=0)return f;
       else return -1;
    }