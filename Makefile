EXDIRS= exercise1-2 exercise3 exercise4 exercise5 exercise6 \
		  exercise7 exercise8 exercise9 exercise10 exercise11 \
		  exercise12 exercise13 exercise14 exercise15 exercise16 \
		  exercise17 exercise18

all:
	$(foreach var,$(EXDIRS),cd $(var); make; cd ../;)

allclean:
	$(foreach var,$(EXDIRS),cd $(var); make clean; cd ../;)
