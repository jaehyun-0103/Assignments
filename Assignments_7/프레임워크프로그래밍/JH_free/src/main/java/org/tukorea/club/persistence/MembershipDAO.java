package org.tukorea.club.persistence;

import org.tukorea.club.domain.MembershipVO;

public interface MembershipDAO {
	public void add(MembershipVO vo) throws Exception;

	public void delete(MembershipVO vo) throws Exception;
}