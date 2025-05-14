with gp as (
    select n.fish_type, fish_name, max(length) as length
    from fish_info f join fish_name_info n on f.fish_type = n.fish_type
    group by n.fish_name, n.fish_type
     )
select f.id, gp.fish_name, f.length
from gp join fish_info f on (gp.fish_type=f.fish_type and gp.length=f.length)
order by f.id;