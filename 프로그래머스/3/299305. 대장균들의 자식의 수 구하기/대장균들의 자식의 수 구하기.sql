select e.ID, (
    select count(*)
    from ECOLI_DATA a
    where a.PARENT_ID = e.ID
) as CHILD_COUNT
from ECOLI_DATA e


