frame(elephantidae, subclase_de(proboscidea), propiedades([son(elefantes)])).
frame(equidae, subclase_de(perissodactyla), propiedades([son(compatibles)])).
frame(rhinocerotidae, subclase_de(perissodactyla), propiedades([tien(cuerno)])).
frame(ursidae, subclase_de(carnivora), propiedades([son(osos)])).
frame(noctilionoidea, subclase_de(chiroptera), propiedades([es(pescador)])).
frame(animal, subclase_de(objeto), propiedades([puede(sentir), puede(respirar)])).
frame(mamifero, subclase_de(animal), propiedades([puede(mamar), respira(aire)])).
frame(artiodactilo, subclase_de(mamifero), propiedades([tiene(pesugnas_pares), comen(plantas)])).
frame(carnivora, subclase_de(mamifero), propiedades([comen(carne)])).
frame(primates, subclase_de(mamifero), propiedades([tiene(cerebro_desarrollado)])).
frame(proboscidea, subclase_de(mamifero), propiedades([es(grande)])).
frame(perissodactyla, subclase_de(mamifero), propiedades([tiene(pesugnas_impares)])).
frame(chiroptera, subclase_de(mamifero), propiedades([tien(alas), es(roedor)])).
frame(camelidos, subclase_de(artiodactilo), propiedades([familia_de(camellos)])).
frame(canidae, subclase_de(carnivora), propiedades([puede(comer_vegetales)])).
frame(suidae, subclase_de(artiodactilo), propiedades([son(inteligentes)])).
frame(hominidae, subclase_de(primates), propiedades([son(grandes_simios)])).
frame(felidae, subclase_de(carnivora), propiedades([son(felinos)])).

frame(elefante_asiatico, subclase_de(elephantidae), propiedades([nombre_cientifico(elephas_maximus), imagen('elefante.png')])).
frame(caballo, subclase_de(equidae), propiedades([nombre_cientifico(equus_caballus), ruido(relincha), imagen('caballo.png')])).
frame(rinoceronte_blanco, subclase_de(rhinocerotidae), propiedades([nombre_cientifico(ceratotherium_simum), imagen('rino.png')])).
frame(oso_pardo, subclase_de(ursidae), propiedades([nombre_cientifico(ursus_arctos), pelaje(marron), imagen('pardo.png')])).
frame(oso_polar, subclase_de(ursidae), propiedades([nombre_cientifico(ursus_maritimus), pelaje(blanco), imagen('polar.png')])).
frame(panda, subclase_de(ursidae), propiedades([nombre_cientifico(ailuropoda_melanoleuca), pelaje(blanco_y_negro), imagen('panda.png')])).
frame(murcielago, subclase_de(noctilionoidea), propiedades([nombre_cientifico(noctilio_albiventris), imagen('dracula.png')])).
frame(vicugna, subclase_de(camelidos), propiedades([nombre_cientifico(vicugna_vicugna), imagen('vicugna_vicugna.png')])).
frame(guanaco, subclase_de(camelidos), propiedades([nombre_cientifico(lama_guanicoe), imagen('guanaco.png')])).
frame(llama, subclase_de(camelidos), propiedades([nombre_cientifico(lama_pacos), imagen('llama.png')])).
frame(perro, subclase_de(canidae), propiedades([nombre_cientifico(canis_lupus_familiaris), imagen('guagua.png')])).
frame(lobo_rojo, subclase_de(canidae), propiedades([nombre_cientifico(canis_rufus), imagen('lobo_rojo.png')])).
frame(coyote, subclase_de(canidae), propiedades([nombre_cientifico(canis_latrans), imagen('coyote.png')])).
frame(babirusa, subclase_de(suidae), propiedades([nombre_cientifico(babyrousa_babyrussa), imagen('babirusa.png')])).
frame(jabali, subclase_de(suidae), propiedades([nombre_cientifico(pumba_o_sus_scrofa), imagen('jabali.png')])).
frame(chimpance, subclase_de(hominidae), propiedades([nombre_cientifico(pan_troglodytes), vive_en(selvas), imagen('chimpance.png')])).
frame(gorila, subclase_de(hominidae), propiedades([nombre_cientifico(gorilla_gorilla), vive_en(bosques_costeros), imagen('gorila.png')])).
frame(orangutan, subclase_de(hominidae), propiedades([nombre_cientifico(pongo_pygmaeus), vive_en(selvas), imagen('orangutan.png')])).
frame(puma, subclase_de(felidae), propiedades([nombre_cientifico(puma_concolor), es(pequegna), emite(maullidos), imagen('puma.png')])).
frame(leopardo, subclase_de(felidae), propiedades([nombre_cientifico(panthera_pardus), es(rapido), imagen('leopardo.png')])).
frame(gato_montes, subclase_de(felidae), propiedades([nombre_cientifico(leopardus_geoffroyi), es(chiquito), imagen('montes.png')])).

que_es(X):-((instancia(X),es(Clase,X));
(subclase(X),subc(X,Clase))),Clase\=objeto,write('Es '),writeln(Clase),fail.
es(Clase,Obj):- frame(Obj,instancia_de(Clase),_).
es(Clase,Obj):- frame(Obj,instancia_de(Clasep),_),subc(Clasep,Clase).
subc(C1,C2):- frame(C1,subclase_de(C2),_).
subc(C1,C2):- frame(C1,subclase_de(C3),_),subc(C3,C2).
subclase(X):-frame(X,subclase_de(_),_).
instancia(X):-frame(X,instancia_de(_),_).
propiedadesc(objeto):-!.
propiedadesc(X):-frame(X,subclase_de(Y),propiedades(Z)),imprime(Z),propiedadesc(Y).
propiedadesi(X):-frame(X,instancia_de(Y),propiedades(Z)),imprime(Z),propiedadesc(Y).
props(X):-(instancia(X),propiedadesi(X));(subclase(X),propiedadesc(X)).
imprime([]):-!.
imprime([H|T]):-writeln(H),imprime(T).
about(X):-que_es(X);props(X).