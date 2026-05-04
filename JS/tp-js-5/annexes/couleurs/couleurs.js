function createtab(r,g,b,r2,g2,b2,id)
{
    i=200
    j=200
    dr=(r2-r)/(i*j);
    dg=(g2-g)/(i*j);
    db=(b2-b)/(i*j);
    tab=document.getElementById(id);
    tab.style.width="600px";
    tab.style.height="600px";
    for (let index = 1; index < i; index++) {
        tr=document.createElement("tr");
        for (let index2 = 1; index2 < j; index2++) {
            td=document.createElement("td");
            td.style.backgroundColor="rgb("+(r+dr*(i*index+index2))+","+(g+dg*(i*index+index2))+","+(b+db*(i*index+index2))+")"
            tr.appendChild(td)
    }
        tab.appendChild(tr);
    }
}

createtab(Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,"tab1");
createtab(Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,"tab2");
createtab(Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,Math.random()*255,"tab3");
