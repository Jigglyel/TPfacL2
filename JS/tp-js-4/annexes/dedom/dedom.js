form=document.getElementsByTagName("form");
form=form[0];
text=form.previousElementSibling;
form.parentNode.removeChild(form);
text.parentNode.removeChild(text);


cellules=document.getElementsByTagName("td");

for(let c of cellules)
{
    c.style.textAlign="center";
    c.style.border="solid";
    c.style.borderWidth="1px";
    c.style.borderColor="purple";
    
}


tabs=document.getElementsByTagName("table");

for(let t of tabs)
{
    t.style.borderCollapse="collapse";
}


intro=document.getElementById("intro");
p=intro.nextElementSibling;
intro.parentNode.removeChild(intro);
p.parentNode.removeChild(p);

liste=document.querySelector("ol");
for(e of liste.childNodes)
{
    console.log(e)
    
    if(e.textContent[0]=='D')
    {
        e.style.fontFamily="Cursive";
    }
    else if(e.nodeName!="#text")
    {
         e.textContent="\u26A0";
    }
}