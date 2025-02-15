
select a.ID, 
(
    case
    WHEN (a.ranking / a.total_count * 100) <= 25 THEN 'CRITICAL'
    WHEN (a.ranking / a.total_count * 100) <= 50 THEN 'HIGH'
    WHEN (a.ranking / a.total_count * 100) <= 75 THEN 'MEDIUM'
    WHEN (a.ranking / a.total_count * 100) <= 100 THEN 'LOW'
    end) as COLONY_NAME
from (
    select ID, RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) - 1 AS ranking, COUNT(*) OVER () - 1 AS total_count
    from ECOLI_DATA
) a
order by a.ID