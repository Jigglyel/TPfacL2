var tab=s.split(""); 
var tabv=[];
tab.forEach(char => { 
    voyelles.split("").forEach(voyelle =>{
        if(voyelle==char)
        {
            tabv.push(char);
        }
    })  
    
    
});

var map=new Map();

voyelles.split("").forEach(voyelle => {
    map.set(voyelle,tabv.filter(char=>char==voyelle).length);
    
});

var max=Math.max(...map.values());
var maxv;
voyelles.split("").forEach(voyelle => {
    if(map.get(voyelle)==max)
        maxv=voyelle;
    
});