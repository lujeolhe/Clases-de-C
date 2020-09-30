# define TRUE 1
# define FALSE 0

int prueba0(int resultado){
  if(resultado == 0){
    return TRUE;
  }
  return FALSE;
}

int prueba3_1_8_16(int resultado){
  if(resultado == 25){
    return TRUE;
  }

  return FALSE;
}

int prueba_18_16_65535_00(int resultado){
  if(resultado == 65535){
    return TRUE;
  }

  return FALSE;
}
