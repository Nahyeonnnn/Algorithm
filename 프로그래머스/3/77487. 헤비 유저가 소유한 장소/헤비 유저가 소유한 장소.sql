SELECT p.ID, p.NAME, p.HOST_ID
from PLACES p join (
    select host_id, count(host_id) as count_host from PLACES
    group by host_id
) s on p.host_id = s.host_id
where 2 <= s.count_host

