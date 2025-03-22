SELECT i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME
from ANIMAL_INS i join ANIMAL_OUTS o on i.ANIMAL_ID = o.ANIMAL_ID
where SUBSTRING_INDEX(i.SEX_UPON_INTAKE, ' ', 1) = 'Intact' and
(substring_index(o.SEX_UPON_OUTCOME, ' ', 1) = 'Spayed' or substring_index(o.SEX_UPON_OUTCOME, ' ', 1) =  'Neutered')
order by i.ANIMAL_ID

# SELECT i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME, 
# from ANIMAL_INS i join ANIMAL_OUTS o on i.ANIMAL_ID = o.ANIMAL_ID
# where index_substring(i.SEX_UPON_INTAKE, ' ', 1) = 'Intact' and
# index_substring(o.SEX_UPON_OUTCOME, ' ', 1) = 'Spayed' or index_substring(SEX_UPON_OUTCOME, ' ', 1) = 'Neutered'
# order by i.ANIMAL_ID