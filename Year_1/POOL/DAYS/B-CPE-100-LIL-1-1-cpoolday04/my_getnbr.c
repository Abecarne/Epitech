/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_getnbr
*/int  my_getnbr(char  const *str) 
{
    int len = my_strlen(str);                                
    int signe_final = 1;
    long cpt_nb_chiffres = 1;
    int nb_signes = 0;
    int nb_chiffres = 0;
    long nb_final = 0;
    long operation = 0;
    
    
    for (int i = 0; i < len; i++) {

       if (str[i] == '-' || str[i] == '+') {
          nb_signes++;
       } else if (str[i] >= '0' && str[i] <= '9') {
          nb_chiffres++;
       } else {
         len = i;
       }
    }
    
    for (int i = 0; i < nb_signes; i++) {
            if (str[i] == '-') {
            signe_final *= -1;
        }
    }
    for (int i = 0; i < (len - nb_signes) - 1; i++) {
      cpt_nb_chiffres *= 10;
    }
    
    for (int j = nb_signes; j < len; j++) {
      long ce_qui_est_dans_tableau = str[j];
      long remplace = (str[j] - 48);
      operation = (str[j] - 48) * cpt_nb_chiffres;
      nb_final += (operation * signe_final);
      cpt_nb_chiffres /= 10;
    }
    if ((nb_final < -2147483648) || (nb_final > +2147483647) || (nb_final == 0)) {
      nb_final = 0;
    }
    return (nb_final);
}