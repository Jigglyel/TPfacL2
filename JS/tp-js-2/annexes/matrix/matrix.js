function sMatrix(mat)
{ var resu="";
    mat.forEach(ligne => {
        ligne.forEach(lettre => {
            resu+=lettre+" ";
            
        });
        resu+="\n";
    });
    return resu;
}