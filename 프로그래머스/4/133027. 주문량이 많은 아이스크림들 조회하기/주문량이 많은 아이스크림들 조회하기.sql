select j.flavor
from july j join first_half f on j.flavor = f.flavor
group by flavor
order by sum(f.TOTAL_ORDER) + sum(j.TOTAL_ORDER) desc
limit 3