-- 코드를 입력하세요
# SELECT FLAVOR 
select t.FLAVOR
from (
    select (
    select sum(TOTAL_ORDER)
    from JULY
    where FLAVOR = f.FLAVOR
) + (
    select sum(TOTAL_ORDER)
    from FIRST_HALF
    where FLAVOR = f.FLAVOR
) as total, f.FLAVOR
from FIRST_HALF f 
order by total desc
limit 3) t
