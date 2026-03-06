
function prompt_positive_number(base)
{
    var x;
    x=prompt("sasir un nb");;
    x=parseInt(x,base)
    if(!isNaN(parseInt(x)) && parseInt(x)>=0)
        return x;
    else return "c'est de la merde";
}