package org.tukorea.test;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration(locations = "classpath:/applicationContext.xml")
public class JdbcTemplateTest {

	@Autowired
	private JdbcTemplate jt;

	private static Logger logger = LoggerFactory.getLogger(DataSourceTest.class);

	@Test
	public void selectQuery() throws Exception {
		try {
			int count = jt.queryForObject("SELECT COUNT(*) FROM STUDENT", Integer.class);
			logger.info("Count : " + count);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
