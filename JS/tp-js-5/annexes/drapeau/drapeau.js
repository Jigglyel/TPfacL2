function createSimpleNode(tag, options,text)
{
    let html;
    html=document.createElement(tag);
    options.forEach(element => {
    html.setAttribute(element[0],element[1])
        
    });
    
    html.innerText=text;
    return html;
}
    document.body.append(createSimpleNode("img",[["src","https://leria-info.univ-angers.fr/~david.lesaint/esg/l2dw/tp-js-5/drapeau/pix.png"]],""));
    document.body.append(createSimpleNode("br",[[]],""))
    document.body.append(createSimpleNode("a",[["href","https://www.youtube.com/watch?v=n7T6O-nYVaY"]],"très belle game overwatch"));
    document.body.append(createSimpleNode("p",[[]],"6767676767676767676767676767"))
