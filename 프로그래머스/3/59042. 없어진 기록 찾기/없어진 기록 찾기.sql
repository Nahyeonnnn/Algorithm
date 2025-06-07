SELECT o.ANIMAL_ID, o.NAME
from ANIMAL_OUTS o left join ANIMAL_INS i on o.animal_id=i.animal_id
where isnull(i.animal_id)