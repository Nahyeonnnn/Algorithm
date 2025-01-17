select ID, 
    case
        when SIZE_OF_COLONY <= 100 then 'LOW'
        when 100 < SIZE_OF_COLONY && SIZE_OF_COLONY <= 1000 then 'MEDIUM'
        else 'HIGH'
    end SIZE
from ECOLI_DATA
order by ID