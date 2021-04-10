function visualiserLeNoeud(couleur, type, text, prof){
	// console.log(prof + ' : ' + text + '('+couleur+')');
	var u = document.createElement("article")
	var t = document.createTextNode(type +' ' + text);
	u.appendChild(t)
	u.setAttribute("style", "background-color : "+couleur+"; margin : "+prof*10+"px;")
	h.appendChild(u);
	// h.appendChild(document.createElement('br'));
}

function analyseDOM(noeud, prof) {
	if (noeud == null) return;
	let type = 0;
	let couleur;
	switch (noeud.nodeType) {
		case 1 : 
			type = 'Element'; 
			couleur = 'lightblue';
			break;
		case 3 :
			type  = 'Text'
			couleur = 'green'
			break;
		case 9 :
			type = 'Document'
			couleur = 'yellow'
			break;
		default:
			type = 0;
	}
	if (type) {
		visualiserLeNoeud(couleur, type, noeud.nodeName, prof);
	}
	if (noeud.attributes) {
		for (let num=0; num < noeud.attributes.length; num++) {
			visualiserLeNoeud('orange', 'Attribut', noeud.attributes[num].nodeName, prof);
		}
	}
	for (let num=0; num < noeud.childNodes.length; num++) {
		analyseDOM(noeud.childNodes.item(num), prof+1);
	}
}

let h = document.createElement("div");
analyseDOM(document, 0)
document.body.appendChild(h)

