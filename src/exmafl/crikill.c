
all_cri () {
  typeset -i criko criok ncri exa cri proc cpt
  criko=0
  criok=0
  tcri=`./criteria -t | grep -v "Amenesik / Sologic" | grep -v "Criteria" | grep -v "Stat"| grep -v ":" | grep -v "-"| tr -s " " | cut -f7 -d" "`
  texa=`./criteria -t | grep -v "Amenesik / Sologic" | grep -v "Criteria" | grep -v "Stat"| grep -v ":" | grep -v "-"| tr -s " " | cut -f3 -d" "`
  ncri=`echo $tcri | wc | tr -s " " | cut -f3 -d" "`
  cpt=`expr 1`
  while [ $cpt -lt `expr $ncri + 1` ]
   do
      exa=`echo $texa | cut -f$cpt -d" "`
      cri=`echo $tcri | cut -f$cpt -d" "`
      proc=`ps -p$exa | wc -l`
      if [ $proc -lt 2 ]
        then
 	  echo
	  echo $cri tache criteria sans exa associe : $exa arretee
  	  ./criteria -p$cri 2>/dev/null
	  ./access -p$cri 2>/dev/null
	  ./access -p$exa 2>/dev/null
          echo "!\c"
          criko=`expr $criko + 1`
        else
          echo ".\c"
          criok=`expr $criok + 1`
       fi
    cpt=`expr $cpt + 1`
   done
  echo " "
  echo " ! $criko taches criteria arretees"
  echo " . $criok taches criteria en cours d'utilisation."
   
}



all_verif () {

  echo "Verification de criteria. Un instant SVP..."
  all_cri
  exit 0
}


 all_verif

