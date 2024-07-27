SELECT ROUND((COUNT( DISTINCT a1.player_id))/(SELECT COUNT(DISTINCT player_id ) FROM Activity),2) as fraction
FROM (
    SELECT player_id ,MIN(event_date ) as event_date 
    FROM Activity
    GROUP BY  player_id
) a1
INNER JOIN Activity a2 ON a1.player_id = a2.player_id 
WHERE DATEDIFF(a2.event_date,a1.event_date) =1