program " "

#class example

public
	Dcl nom$=64
	Dcl adr$=64
	Dcl ville$=64
	Dcl codepost$=5
	Dcl pays$=64

public	Function Show:()
	Print=1:($,/1),nom,adr,ville,codepost,pays
	Print=1:"---------------------------------",tabv(1)
end

#endclass example

example A
example B
example C
example D

segment 0

	Read=0:A.nom,A.adr,A.ville,A.codepost,A.pays
	A.Show
	Read=0:B.nom,B.adr,B.ville,B.codepost,B.pays
	B.show

	Stop

Data	"Depont","Rue d'Ici","Paris","75013","France"
Data	"Derond","Rue d'Ici","Paris","75014","France"
Data	"Dequoi","Rue d'Ici","Paris","75015","France"
Data	"Derien","Rue d'Ici","Paris","75016","France"
eseg 0
end


