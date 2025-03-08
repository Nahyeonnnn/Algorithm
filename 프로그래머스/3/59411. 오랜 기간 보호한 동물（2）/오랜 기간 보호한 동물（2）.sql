SELECT o.ANIMAL_ID, o.NAME
from ANIMAL_OUTS o join ANIMAL_INS i on o.ANIMAL_ID=i.ANIMAL_ID
order by (o.datetime - i.datetime) desc limit 2