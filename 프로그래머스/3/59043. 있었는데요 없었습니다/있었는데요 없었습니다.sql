-- 코드를 입력하세요
SELECT i.ANIMAL_ID, i.NAME
# , i.DATETIME as '보호 시작일', o.DATETIME as' 입양일'
from ANIMAL_OUTS o left join animal_ins i
on i.ANIMAL_ID = o.ANIMAL_ID
where i.DATETIME > o.DATETIME
order by i.DATETIME;